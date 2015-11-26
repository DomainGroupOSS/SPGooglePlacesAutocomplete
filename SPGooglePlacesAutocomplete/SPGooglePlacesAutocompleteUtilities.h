//
//  SPGooglePlacesAutocompleteUtilities.h
//  SPGooglePlacesAutocomplete
//
//  Created by Stephen Poletto on 7/18/12.
//  Copyright (c) 2012 Stephen Poletto. All rights reserved.
//

#define kGoogleAPINSErrorCode 42

@class CLPlacemark;
@class SPGooglePlacesPlaceDetail;

typedef enum {
    SPPlaceTypeInvalid = -1,
    SPPlaceTypeGeocode = 0,
    SPPlaceTypeRegion,
    SPPlaceTypeEstablishment
} SPGooglePlacesAutocompletePlaceType;

typedef void (^SPGooglePlacesPlacemarkResultBlock)(CLPlacemark *placemark, NSString *addressString, NSError *error);
typedef void (^SPGooglePlacesAutocompleteResultBlock)(NSArray *places, NSError *error);
typedef void (^SPGooglePlacesPlaceDetailResultBlock)(SPGooglePlacesPlaceDetail *placeDetails, NSError *error);

extern SPGooglePlacesAutocompletePlaceType SPPlaceTypeFromDictionary(NSDictionary *placeDictionary);
extern NSString *SPBooleanStringForBool(BOOL boolean);
extern NSString *SPPlaceTypeStringForPlaceType(SPGooglePlacesAutocompletePlaceType type);
extern BOOL SPIsEmptyString(NSString *string);

@interface NSArray(SPFoundationAdditions)
- (id)onlyObject;
@end