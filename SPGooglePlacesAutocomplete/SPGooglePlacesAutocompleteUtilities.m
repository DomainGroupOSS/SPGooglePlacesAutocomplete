//
//  SPGooglePlacesAutocompleteUtilities.m
//  SPGooglePlacesAutocomplete
//
//  Created by Stephen Poletto on 7/18/12.
//  Copyright (c) 2012 Stephen Poletto. All rights reserved.
//

#import "SPGooglePlacesAutocompleteUtilities.h"

@implementation NSArray(SPFoundationAdditions)
- (id)onlyObject {
    return [self count] >= 1 ? self[0] : nil;
}
@end

SPGooglePlacesAutocompletePlaceType SPPlaceTypeFromDictionary(NSDictionary *placeDictionary) {
    
    if([[placeDictionary objectForKey:@"types"] containsObject:@"establishment"]){
        
        return SPPlaceTypeEstablishment;
        
    }else if([[placeDictionary objectForKey:@"types"] containsObject:@"geocode"]){
        
        return SPPlaceTypeGeocode;
        
    }else if([[placeDictionary objectForKey:@"types"] containsObject:@"(cities)"]){
        
        return SPPlaceTypeCity;
        
    }else if ([[placeDictionary objectForKey:@"types"] containsObject:@"(regions)"]){
        
        return SPPlaceTypeRegion;
    }
    
    return SPPlaceTypeInvalid;
}

NSString *SPBooleanStringForBool(BOOL boolean) {
    return boolean ? @"true" : @"false";
}

NSString *SPPlaceTypeStringForPlaceType(SPGooglePlacesAutocompletePlaceType type) {
    
    switch (type) {
        case SPPlaceTypeEstablishment:
            return @"establishment";
            
        case SPPlaceTypeGeocode:
            return @"geocode";
            
        case SPPlaceTypeRegion:
            return @"(regions)";
            
        case SPPlaceTypeCity:
            return @"(cities)";
            
        case SPPlaceTypeInvalid:
            return @"";
    }

}

extern BOOL SPIsEmptyString(NSString *string) {
    return !string || ![string length];
}