/* Copyright 2000-2004 The Apache Software Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef APR_TABLES_H
#define APR_TABLES_H

/**
 * @file apr_tables.h
 * @brief APR Table library
 */

#include "apr.h"
#include "apr_pools.h"

#if APR_HAVE_STDARG_H
#include <stdarg.h>     /* for va_list */
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * @defgroup apr_tables Table and Array Functions
 * @ingroup APR 
 * Tables are used to store entirely opaque structures 
 * for applications, while Arrays are usually used to
 * deal with string lists.
 * @{
 */

/** the table abstract data type */
typedef struct apr_table_t apr_table_t;

/** @see apr_array_header_t */
typedef struct apr_array_header_t apr_array_header_t;

/** An opaque array type */
struct apr_array_header_t {
    /** The pool the array is allocated out of */
    apr_pool_t *pool;
    /** The amount of memory allocated for each element of the array */
    int elt_size;
    /** The number of active elements in the array */
    int nelts;
    /** The number of elements allocated in the array */
    int nalloc;
    /** The elements in the array */
    char *elts;
};

/**
 * The (opaque) structure for string-content tables.
 */
typedef struct apr_table_entry_t apr_table_entry_t;

/** The type for each entry in a string-content table */
struct apr_table_entry_t {
    /** The key for the current table entry */
    char *key;          /* maybe NULL in future;
                         * check when iterating thru table_elts
                         */
    /** The value for the current table entry */
    char *val;

    /** A checksum for the key, for use by the apr_table internals */
    apr_uint32_t key_checksum;
};

/**
 * Get the elements from a table
 * @param t The table
 * @return An array containing the contents of the table
 */
APR_DECLARE(const apr_array_header_t *) apr_table_elts(const apr_table_t *t);

/**
 * Determine if the table is empty
 * @param t The table to check
 * @return True if empty, False otherwise
 */
APR_DECLARE(int) apr_is_empty_table(const apr_table_t *t);

/**
 * Determine if the array is empty
 * @param a The array to check
 * @return True if empty, False otherwise
 */
APR_DECLARE(int) apr_is_empty_array(const apr_array_header_t *a);

/**
 * Create an array
 * @param p The pool to allocate the memory out of
 * @param nelts the number of elements in the initial array
 * @param elt_size The size of each element in the array.
 * @return The new array
 */
APR_DECLARE(apr_array_header_t *) apr_array_make(apr_pool_t *p,
                                                 int nelts, int elt_size);

/**
 * Add a new element to an array (as a first-in, last-out stack)
 * @param arr The array to add an element to.
 * @return Location for the new element in the array.
 * @remark If there are no free spots in the array, then this function will
 *         allocate new space for the new element.
 */
APR_DECLARE(void *) apr_array_push(apr_array_header_t *arr);

/**
 * Remove an element from an array (as a first-in, last-out stack)
 * @param arr The array to remove an element from.
 * @return Location of the element in the array.
 * @remark If there are no elements in the array, NULL is returned.
 */
APR_DECLARE(void *) apr_array_pop(apr_array_header_t *arr);

/**
 * Concatenate two arrays together
 * @param dst The destination array, and the one to go first in the combined 
 *            array
 * @param src The source array to add to the destination array
 */
APR_DECLARE(void) apr_array_cat(apr_array_header_t *dst,
			        const apr_array_header_t *src);

/**
 * Copy the entire array
 * @param p The pool to allocate the copy of the array out of
 * @param arr The array to copy
 * @return An exact copy of the array passed in
 * @remark The alternate apr_array_copy_hdr copies only the header, and arranges 
 *         for the elements to be copied if (and only if) the code subsequently
 *         does a push or arraycat.
 */
APR_DECLARE(apr_array_header_t *) apr_array_copy(apr_pool_t *p,
                                      const apr_array_header_t *arr);
/**
 * Copy the headers of the array, and arrange for the elements to be copied if
 * and only if the code subsequently does a push or arraycat.
 * @param p The pool to allocate the copy of the array out of
 * @param arr The array to copy
 * @return An exact copy of the array passed in
 * @remark The alternate apr_array_copy copies the *entire* array.
 */
APR_DECLARE(apr_array_header_t *) apr_array_copy_hdr(apr_pool_t *p,
                                      const apr_array_header_t *arr);

/**
 * Append one array to the end of another, creating a new array in the process.
 * @param p The pool to allocate the new array out of
 * @param first The array to put first in the new array.
 * @param second The array to put second in the new array.
 * @return A new array containing the data from the two arrays passed in.
*/
APR_DECLARE(apr_array_header_t *) apr_array_append(apr_pool_t *p,
                                      const apr_array_header_t *first,
                                      const apr_array_header_t *second);

/**
 * Generates a new string from the apr_pool_t containing the concatenated 
 * sequence of substrings referenced as elements within the array.  The string 
 * will be empty if all substrings are empty or null, or if there are no 
 * elements in the array.  If sep is non-NUL, it will be inserted between 
 * elements as a separator.
 * @param p The pool to allocate the string out of
 * @param arr The array to generate the string from
 * @param sep The separator to use
 * @return A string containing all of the data in the array.
 */
APR_DECLARE(char *) apr_array_pstrcat(apr_pool_t *p,
				      const apr_array_header_t *arr,
				      const char sep);

/**
 * Make a new table
 * @param p The pool to allocate the pool out of
 * @param nelts The number of elements in the initial table.
 * @return The new table.
 * @warning This table can only store text data
 */
APR_DECLARE(apr_table_t *) apr_table_make(apr_pool_t *p, int nelts);

/**
 * Create a new table and copy another table into it
 * @param p The pool to allocate the new table out of
 * @param t The table to copy
 * @return A copy of the table passed in
 */
APR_DECLARE(apr_table_t *) apr_table_copy(apr_pool_t *p,
                                          const apr_table_t *t);

/**
 * Delete all of the elements from a table
 * @param t The table to clear
 */
APR_DECLARE(void) apr_table_clear(apr_table_t *t);

/**
 * Get the value associated with a given key from the table.  After this call,
 * The data is still in the table
 * @param t The table to search for the key
 * @param key The key to search for
 * @return The value associated with the key
 */
APR_DECLARE(const char *) apr_table_get(const apr_table_t *t, const char *key);

/**
 * Add a key/value pair to a table, if another element already exists with the
 * same key, this will over-write the old data.
 * @param t The table to add the data to.
 * @param key The key fo use
 * @param val The value to add
 * @remark When adding data, this function makes a copy of both the key and the
 *         value.
 */
APR_DECLARE(void) apr_table_set(apr_table_t *t, const char *key,
                                const char *val);

/**
 * Add a key/value pair to a table, if another element already exists with the
 * same key, this will over-write the old data.
 * @param t The table to add the data to.
 * @param key The key to use
 * @param val The value to add
 * @warning When adding data, this function does not make a copy of the key or 
 *          the value, so care should be taken to ensure that the values will 
 *          not change after they have been added..
 */
APR_DECLARE(void) apr_table_setn(apr_table_t *t, const char *key,
                                 const char *val);

/**
 * Remove data from the table
 * @param t The table to remove data from
 * @param key The key of the data being removed
 */
APR_DECLARE(void) apr_table_unset(apr_table_t *t, const char *key);

/**
 * Add data to a table by merging the value with data that has already been 
 * stored
 * @param t The table to search for the data
 * @param key The key to merge data for
 * @param val The data to add
 * @remark If the key is not found, then this function acts like apr_table_add
 */
APR_DECLARE(void) apr_table_merge(apr_table_t *t, const char *key,
                                  const char *val);

/**
 * Add data to a table by merging the value with data that has already been 
 * stored
 * @param t The table to search for the data
 * @param key The key to merge data for
 * @param val The data to add
 * @remark If the key is not found, then this function acts like apr_table_addn
 */
APR_DECLARE(void) apr_table_mergen(apr_table_t *t, const char *key,
                                   const char *val);

/**
 * Add data to a table, regardless of whether there is another element with the
 * same key.
 * @param t The table to add to
 * @param key The key to use
 * @param val The value to add.
 * @remark When adding data, this function makes a copy of both the key and the
 *         value.
 */
APR_DECLARE(void) apr_table_add(apr_table_t *t, const char *key,
                                const char *val);

/**
 * Add data to a table, regardless of whether there is another element with the
 * same key.
 * @param t The table to add to
 * @param key The key to use
 * @param val The value to add.
 * @remark When adding data, this function does not make a copy of the key or the
 *         value, so care should be taken to ensure that the values will not 
 *         change after they have been added..
 */
APR_DECLARE(void) apr_table_addn(apr_table_t *t, const char *key,
                                 const char *val);

/**
 * Merge two tables into one new table
 * @param p The pool to use for the new table
 * @param overlay The first table to put in the new table
 * @param base The table to add at the end of the new table
 * @return A new table containing all of the data from the two passed in
 */
APR_DECLARE(apr_table_t *) apr_table_overlay(apr_pool_t *p,
                                             const apr_table_t *overlay,
                                             const apr_table_t *base);

/**
 * Declaration prototype for the iterator callback function of apr_table_do()
 * and apr_table_vdo().
 * @param rec The data passed as the first argument to apr_table_[v]do()
 * @param key The key from this iteration of the table
 * @param value The value from this iteration of the table
 * @remark Iteration continues while this callback function returns non-zero.
 * To export the callback function for apr_table_[v]do() it must be declared 
 * in the _NONSTD convention.
 */
typedef int (apr_table_do_callback_fn_t)(void *rec, const char *key, 
                                                    const char *value);

/** 
 * Iterate over a table running the provided function once for every
 * element in the table.  If there is data passed in as a vararg, then the 
 * function is only run on those elements whose key matches something in 
 * the vararg.  If the vararg is NULL, then every element is run through the
 * function.  Iteration continues while the function returns non-zero.
 * @param comp The function to run
 * @param rec The data to pass as the first argument to the function
 * @param t The table to iterate over
 * @param ... The vararg.  If this is NULL, then all elements in the table are
 *            run through the function, otherwise only those whose key matches
 *            are run.
 * @return FALSE if one of the comp() iterations returned zero; TRUE if all
 *            iterations returned non-zero
 * @see apr_table_do_callback_fn_t
 */
APR_DECLARE_NONSTD(int) apr_table_do(apr_table_do_callback_fn_t *comp,
                                     void *rec, const apr_table_t *t, ...);

/** 
 * Iterate over a table running the provided function once for every
 * element in the table.  If there is data passed in as a vararg, then the 
 * function is only run on those element's whose key matches something in 
 * the vararg.  If the vararg is NULL, then every element is run through the
 * function.  Iteration continues while the function returns non-zero.
 * @param comp The function to run
 * @param rec The data to pass as the first argument to the function
 * @param t The table to iterate over
 * @param vp The vararg table.  If this is NULL, then all elements in the 
 *                table are run through the function, otherwise only those 
 *                whose key matches are run.
 * @return FALSE if one of the comp() iterations returned zero; TRUE if all
 *            iterations returned non-zero
 * @see apr_table_do_callback_fn_t
 */
APR_DECLARE(int) apr_table_vdo(apr_table_do_callback_fn_t *comp,
                               void *rec, const apr_table_t *t, va_list vp);

/** flag for overlap to use apr_table_setn */
#define APR_OVERLAP_TABLES_SET   (0)
/** flag for overlap to use apr_table_mergen */
#define APR_OVERLAP_TABLES_MERGE (1)
/**
 * For each element in table b, either use setn or mergen to add the data
 * to table a.  Which method is used is determined by the flags passed in.
 * @param a The table to add the data to.
 * @param b The table to iterate over, adding its data to table a
 * @param flags How to add the table to table a.  One of:
 *          APR_OVERLAP_TABLES_SET        Use apr_table_setn
 *          APR_OVERLAP_TABLES_MERGE      Use apr_table_mergen
 * @remark  This function is highly optimized, and uses less memory and CPU cycles
 *          than a function that just loops through table b calling other functions.
 */
/**
 *<PRE>
 * Conceptually, apr_table_overlap does this:
 *
 *  apr_array_header_t *barr = apr_table_elts(b);
 *  apr_table_entry_t *belt = (apr_table_entry_t *)barr->elts;
 *  int i;
 *
 *  for (i = 0; i < barr->nelts; ++i) {
 *      if (flags & APR_OVERLAP_TABLES_MERGE) {
 *          apr_table_mergen(a, belt[i].key, belt[i].val);
 *      }
 *      else {
 *          apr_table_setn(a, belt[i].key, belt[i].val);
 *      }
 *  }
 *
 *  Except that it is more efficient (less space and cpu-time) especially
 *  when b has many elements.
 *
 *  Notice the assumptions on the keys and values in b -- they must be
 *  in an ancestor of a's pool.  In practice b and a are usually from
 *  the same pool.
 * </PRE>
 */

APR_DECLARE(void) apr_table_overlap(apr_table_t *a, const apr_table_t *b,
                                     unsigned flags);

/**
 * Eliminate redundant entries in a table by either overwriting
 * or merging duplicates
 *
 * @param t Table.
 * @param flags APR_OVERLAP_TABLES_MERGE to merge, or
 *              APR_OVERLAP_TABLES_SET to overwrite
 */
APR_DECLARE(void) apr_table_compress(apr_table_t *t, unsigned flags);

/** @} */

#ifdef __cplusplus
}
#endif

#endif	/* ! APR_TABLES_H */
