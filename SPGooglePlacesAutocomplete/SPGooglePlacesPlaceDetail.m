//
//  SPGooglePlacesPlaceDetail.m
//  SPGooglePlacesAutocompleteDemo
//
//  Created by Ricardo Ruiz Lopez on 25/11/2015.
//  Copyright © 2015 tickbox.com.au. All rights reserved.
//

#import "SPGooglePlacesPlaceDetail.h"

@implementation SPGooglePlacesPlaceDetail

- (instancetype)initWithPlaceDetailsFromDictionary:(NSDictionary *)dictionary apiKey:(NSString *)apiKey {
    
    self = [super init];
    if (self) {

        NSAssert(dictionary, @"There must be a dict to map it into a SPGooglePlacesPlaceDetail object.");
        NSAssert(apiKey, @"There must be a apiKey when creating a SPGooglePlacesPlaceDetail object.");
    
        _name = dictionary[@"name"];
        _formattedAddress = dictionary[@"formatted_address"];
        _reference = dictionary[@"reference"];
        _identifier = dictionary[@"id"];
        _key = apiKey;

        NSNumber *latitude = dictionary[@"geometry"][@"location"][@"lat"];
        NSNumber *longitude = dictionary[@"geometry"][@"location"][@"lng"];
        if (latitude && longitude) {
            _location = [[CLLocation alloc] initWithLatitude:latitude.doubleValue longitude:longitude.doubleValue];
        }
    }
    return self;
}

+ (instancetype)placeDetailsFromDictionary:(NSDictionary *)dictionary apiKey:(NSString *)apiKey {
    return [[self alloc] initWithPlaceDetailsFromDictionary:dictionary apiKey:apiKey];
}

- (NSString *)description {
    return [NSString stringWithFormat:@"Name: %@, Reference: %@, Identifier: %@, Address: %@, Location: %@",
            self.name, self.reference, self.identifier, self.formattedAddress, self.location];
}

@end
