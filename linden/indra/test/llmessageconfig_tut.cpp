/** 
 * @file llmessageconfig_tut.cpp
 * @date   March 2007
 * @brief LLMessageConfig unit tests
 *
 * $LicenseInfo:firstyear=2006&license=viewergpl$
 * 
 * Copyright (c) 2006-2008, Linden Research, Inc.
 * 
 * Second Life Viewer Source Code
 * The source code in this file ("Source Code") is provided by Linden Lab
 * to you under the terms of the GNU General Public License, version 2.0
 * ("GPL"), unless you have obtained a separate licensing agreement
 * ("Other License"), formally executed by you and Linden Lab.  Terms of
 * the GPL can be found in doc/GPL-license.txt in this distribution, or
 * online at http://secondlifegrid.net/programs/open_source/licensing/gplv2
 * 
 * There are special exceptions to the terms and conditions of the GPL as
 * it is applied to this Source Code. View the full text of the exception
 * in the file doc/FLOSS-exception.txt in this software distribution, or
 * online at http://secondlifegrid.net/programs/open_source/licensing/flossexception
 * 
 * By copying, modifying or distributing this software, you acknowledge
 * that you have read and understood your obligations described above,
 * and agree to abide by those obligations.
 * 
 * ALL LINDEN LAB SOURCE CODE IS PROVIDED "AS IS." LINDEN LAB MAKES NO
 * WARRANTIES, EXPRESS, IMPLIED OR OTHERWISE, REGARDING ITS ACCURACY,
 * COMPLETENESS OR PERFORMANCE.
 * $/LicenseInfo$
 */

#include "linden_common.h"
#include "llmessageconfig.h"
#include "lltut.h"
#include "llsdserialize.h"
#include "llfile.h"
#include "lltimer.h"
#include "llframetimer.h"
#include "llsdutil.h"

namespace tut
{
	struct LLMessageConfigTestData {
		std::string mTestConfigDir;

		LLMessageConfigTestData()
		{
			LLUUID random;
			random.generate();
			// generate temp dir
			std::ostringstream oStr;
#if LL_WINDOWS 
			oStr << "llmessage-config-test-" << random;
#else
			oStr << "/tmp/llmessage-config-test-" << random;
#endif
			mTestConfigDir = oStr.str();
			LLFile::mkdir(mTestConfigDir);
			writeConfigFile(LLSD());
			LLMessageConfig::initClass("simulator", mTestConfigDir);
		}

		~LLMessageConfigTestData()
		{
			// rm contents of temp dir
			int rmfile = LLFile::remove((mTestConfigDir + "/message.xml"));
			ensure_equals("rmfile value", rmfile, 0);
			// rm temp dir
			int rmdir = LLFile::rmdir(mTestConfigDir);
			ensure_equals("rmdir value", rmdir, 0);
		}

		void writeConfigFile(const LLSD& config)
		{
			llofstream file((mTestConfigDir + "/message.xml"));
			if (file.is_open())
			{
				LLSDSerialize::toPrettyXML(config, file);
			}
			file.close();
		}
	};
	
	typedef test_group<LLMessageConfigTestData> LLMessageConfigTestGroup;
	typedef LLMessageConfigTestGroup::object LLMessageConfigTestObject;
	LLMessageConfigTestGroup llMessageConfigTestGroup("LLMessageConfig");
	
	template<> template<>
	void LLMessageConfigTestObject::test<1>()
		// tests server defaults
	{
		LLSD config;
		config["serverDefaults"]["simulator"] = "template";
		LLMessageConfig::useConfig(config);
		ensure_equals("Ensure server default is not template",
					  LLMessageConfig::getServerDefaultFlavor(),
					  LLMessageConfig::TEMPLATE_FLAVOR);
	}

	template<> template<>
	void LLMessageConfigTestObject::test<2>()
		// tests message flavors
	{
		LLSD config;
		config["serverDefaults"]["simulator"] = "template";
		config["messages"]["msg1"]["flavor"] = "template";
		config["messages"]["msg2"]["flavor"] = "llsd";
		LLMessageConfig::useConfig(config);
		ensure_equals("Ensure msg template flavor",
					  LLMessageConfig::getMessageFlavor("msg1"),
					  LLMessageConfig::TEMPLATE_FLAVOR);
		ensure_equals("Ensure msg llsd flavor",
					  LLMessageConfig::getMessageFlavor("msg2"),
					  LLMessageConfig::LLSD_FLAVOR);
	}

	template<> template<>
	void LLMessageConfigTestObject::test<4>()
		// tests message flavor defaults
	{
		LLSD config;
		config["serverDefaults"]["simulator"] = "llsd";
		config["messages"]["msg1"]["trusted-sender"] = true;
		LLMessageConfig::useConfig(config);
		ensure_equals("Ensure missing message gives no flavor",
					  LLMessageConfig::getMessageFlavor("Test"),
					  LLMessageConfig::NO_FLAVOR);
		ensure_equals("Ensure missing flavor is NO_FLAVOR even with sender trustedness set",
					  LLMessageConfig::getMessageFlavor("msg1"),
					  LLMessageConfig::NO_FLAVOR);
		ensure_equals("Ensure server default is llsd",
					  LLMessageConfig::getServerDefaultFlavor(),
					  LLMessageConfig::LLSD_FLAVOR);
	}

	template<> template<>
	void LLMessageConfigTestObject::test<3>()
		// tests trusted/untrusted senders
	{
		LLSD config;
		config["serverDefaults"]["simulator"] = "template";
		config["messages"]["msg1"]["flavor"] = "llsd";
		config["messages"]["msg1"]["trusted-sender"] = false;
		config["messages"]["msg2"]["flavor"] = "llsd";
		config["messages"]["msg2"]["trusted-sender"] = true;
		LLMessageConfig::useConfig(config);
		ensure_equals("Ensure untrusted is untrusted",
					  LLMessageConfig::getSenderTrustedness("msg1"),
					  LLMessageConfig::UNTRUSTED);
		ensure_equals("Ensure trusted is trusted",
					  LLMessageConfig::getSenderTrustedness("msg2"),
					  LLMessageConfig::TRUSTED);
		ensure_equals("Ensure missing trustedness is NOT_SET",
					  LLMessageConfig::getSenderTrustedness("msg3"),
					  LLMessageConfig::NOT_SET);
	}
	
	template<> template<>
	void LLMessageConfigTestObject::test<5>()
		// tests trusted/untrusted without flag, only flavor
	{
		LLSD config;
		config["serverDefaults"]["simulator"] = "template";
		config["messages"]["msg1"]["flavor"] = "llsd";
		LLMessageConfig::useConfig(config);
		ensure_equals("Ensure msg1 exists, has llsd flavor",
					  LLMessageConfig::getMessageFlavor("msg1"),
					  LLMessageConfig::LLSD_FLAVOR);
		ensure_equals("Ensure missing trusted is not set",
					  LLMessageConfig::getSenderTrustedness("msg1"),
					  LLMessageConfig::NOT_SET);
	}

	template<> template<>
	void LLMessageConfigTestObject::test<6>()
	{
		LLSD config;
		config["capBans"]["MapLayer"] = true;
		config["capBans"]["MapLayerGod"] = false;
		LLMessageConfig::useConfig(config);
		ensure_equals("Ensure cap ban true MapLayer",
					  LLMessageConfig::isCapBanned("MapLayer"),
					  true);
		ensure_equals("Ensure cap ban false",
					  LLMessageConfig::isCapBanned("MapLayerGod"),
					  false);
	}

	template<> template<>
	void LLMessageConfigTestObject::test<7>()
		// tests that config changes are picked up/refreshed periodically
	{
		LLSD config;
		config["serverDefaults"]["simulator"] = "llsd";
		writeConfigFile(config);

		// wait for it to reload after N seconds
		ms_sleep(6*1000);
		LLFrameTimer::updateFrameTime();
		ensure_equals("Ensure reload after 6 seconds",
					  LLMessageConfig::getServerDefaultFlavor(),
					  LLMessageConfig::LLSD_FLAVOR);
	}

	template<> template<>
	void LLMessageConfigTestObject::test<8>()
		// tests that config changes are picked up/refreshed periodically
	{
		LLSD config;
		config["serverDefaults"]["simulator"] = "template";
		config["messages"]["msg1"]["flavor"] = "llsd";
		config["messages"]["msg1"]["only-send-latest"] = true;
		config["messages"]["msg2"]["flavor"] = "llsd";
		config["messages"]["msg2"]["only-send-latest"] = false;
		LLMessageConfig::useConfig(config);
		ensure_equals("Ensure msg1 exists, sent latest-only",
					  LLMessageConfig::onlySendLatest("msg1"),
					  true);
		ensure_equals("Ensure msg2 exists, sent latest-only",
					  LLMessageConfig::onlySendLatest("msg2"),
					  false);
	}

	template<> template<>
	void LLMessageConfigTestObject::test<9>()
		 // tests that event queue max is reloaded
	{
		LLSD config;
		config["maxQueuedEvents"] = 200;
		LLMessageConfig::useConfig(config);
		ensure_equals("Ensure setting maxQueuedEvents",
					  LLMessageConfig::getMaxQueuedEvents(),
					  200);

		LLMessageConfig::useConfig(LLSD());
		ensure_equals("Ensure default of event queue max 100",
					  LLMessageConfig::getMaxQueuedEvents(),
					  100);
	}	 
}
