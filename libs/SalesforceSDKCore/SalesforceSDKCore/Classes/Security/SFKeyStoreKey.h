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

NS_ASSUME_NONNULL_BEGIN

/**
 Data object representing the encryption key used for encrypting/decrypting the key store.
 */
@interface SFKeyStoreKey : NSObject <NSCoding, NSCopying>

/**
 Create a new SFKeyStoreKey
 */
+ (instancetype) createKey;

/**
 Designated initializer.
 @param key The encryption key for the key store.
 */
- (instancetype)initWithKey:(SFEncryptionKey *)key;

/**
 Read from key chain
 @param keychainId Identifier in the key chain
 @param archiverKey Key used in archiver
 */
+ (nullable instancetype)fromKeyChain:(NSString*)keychainId archiverKey:(NSString*)archiverKey;

/**
 Save to key chain
 @param keychainId Identifier in the key chain
 @param archiverKey Key to use in archiver
 */
- (OSStatus) toKeyChain:(NSString*)keychainId archiverKey:(NSString*)archiverKey;

/**
 Encrypt given data
 @param dataToEncrypt The data to encrypt
 */
- (NSData*)encryptData:(NSData *)dataToEncrypt;

/**
 Decrypt given data
 @param dataToDecrypt The data to decrypt
 */
- (NSData*)decryptData:(NSData *)dataToDecrypt;

/**
 The encryption key for the key store.
 */
@property (nonatomic, strong) SFEncryptionKey *encryptionKey;

@end

NS_ASSUME_NONNULL_END
