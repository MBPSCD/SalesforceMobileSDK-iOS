/*
 Copyright (c) 2014-present, salesforce.com, inc. All rights reserved.
 
 Redistribution and use of this software in source and binary forms, with or without modification,
 are permitted provided that the following conditions are met:
 * Redistributions of source code must retain the above copyright notice, this list of conditions
 and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice, this list of
 conditions and the following disclaimer in the documentation and/or other materials provided
 with the distribution.
 * Neither the name of salesforce.com, inc. nor the names of its contributors may be used to
 endorse or promote products derived from this software without specific prior written
 permission of salesforce.com, inc.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
 IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY
 WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import <Foundation/Foundation.h>
#import "SFEncryptionKey.h"
#import "SFKeyStoreKey.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Singleton class to manage operations on the key store.
 */
@interface SFKeyStoreManager : NSObject

/**
 @return The singleton instance of the key store manager.
 */
+ (instancetype)sharedInstance;

/**
 Retrieves a key with the given label from the key store, or `nil` depending on the autoCreate value.
 @param keyLabel The label associated with the stored key.
 @param create Indicates whether a new key should be created if one does not exist.
 @return The encryption key, or `nil` depending on the autoCreate value.
 */
- (SFEncryptionKey *)retrieveKeyWithLabel:(NSString *)keyLabel autoCreate:(BOOL)create;

/**
 Stores a key with the given label in the key store encrypted by the store's key.
 @param key The encryption key to store.
 @param keyLabel The label associated with the key.
 */
- (void)storeKey:(SFEncryptionKey *)key withLabel:(NSString *)keyLabel;

/**
 Removes the key with the given label from the key store.
 @param keyLabel The label associated with the key to remove.
 */
- (void)removeKeyWithLabel:(NSString *)keyLabel;

/**
 Determines whether a key with the given label exists.
 @param keyLabel The label associated with the key to query.
 @return YES if the key exists in the key store, NO otherwise.
 */
- (BOOL)keyWithLabelExists:(NSString *)keyLabel;

/**
 Returns a key with a random value for the key and initialization vector.  The key size
 will be the size for the AES-256 algorithm (kCCKeySizeAES256), and the initialization
 vector will be the block size associated with AES encryption (kCCBlockSizeAES128).
 @return An instance of SFEncryptionKey with the described values.
 */
- (SFEncryptionKey *)keyWithRandomValue SFSDK_DEPRECATED(7.1, 8.0, "Use SFEncryptionKey:createKey instead");

@end

NS_ASSUME_NONNULL_END
