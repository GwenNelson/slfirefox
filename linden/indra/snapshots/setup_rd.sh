#!/bin/sh
umount /tmp/viewer_displays
umount $1
/sbin/mke2fs $1
rm -rf /tmp/viewer_displays
mkdir /tmp/viewer_displays

mount $1 /tmp/viewer_displays
for ((x=0;x<=8;x+=1)); do
mkdir /tmp/viewer_displays/$x
cp blank.tga /tmp/viewer_displays/$x/a.tga
cp blank.tga /tmp/viewer_displays/$x/b.tga
ln /tmp/viewer_displays/$x/a.tga /tmp/viewer_displays/$x/current.tga
done
chmod -R 777 /tmp/viewer_displays
