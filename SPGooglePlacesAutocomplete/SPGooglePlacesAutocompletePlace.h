//
//  SPGooglePlacesAutocompletePlace.h
//  SPGooglePlacesAutocomplete
//
//  Created by Stephen Poletto on 7/17/12.
//  Copyright (c) 2012 Stephen Poletto. All rights reserved.
//

#import <CoreLocation/CoreLocation.h>
#import "SPGooglePlacesAutocompleteUtilities.h"

/*
{
    description = "London, KY, United States";
    id = 692adb38e4db9759599d6f73f300a3bba7db714a;
    "matched_substrings" =     (
                                {
                                    length = 6;
                                    offset = 0;
                                }
                                );
    "place_id" = "ChIJA8c2lxTNXIgRmMwHc-RRGWI";
    reference = "CkQxAAAA4kLuNAdqnWt8yGE-QnH6ZCHI3_GlceGfBZ8drewYDT0mIbrAFAHMlEoc8biAMIuu4sdLuZD6Ty1RbXDzFE1vaxIQ4b9s9iShhIPaXk0w5m2NuhoUdfTisa5Ct22N4Es8F3VcVBNnADI";
    terms =     (
                 {
                     offset = 0;
                     value = London;
                 },
                 {
                     offset = 8;
                     value = KY;
                 },
                 {
                     offset = 12;
                     value = "United States";
                 }
                 );
    types =     (
                 locality,
                 political,
                 geocode
                 );
}
*/
@interface SPGooglePlacesAutocompletePlace : NSObject {
    CLGeocoder *geocoder;
}

+ (SPGooglePlacesAutocompletePlace *)placeFromDictionary:(NSDictionary *)placeDictionary apiKey:(NSString *)apiKey;

/*!
 Contains the human-readable name for the returned result. For establishment results, this is usually the business name.
 */
@property (nonatomic, strong, readonly) NSString *name;

/*!
 Contains the primary 'type' of this place (i.e. "establishment" or "gecode").
 */
@property (nonatomic, readonly) SPGooglePlacesAutocompletePlaceType type;

/*!
 Contains a unique token that you can use to retrieve additional information about this place in a Place Details request. You can store this token and use it at any time in future to refresh cached data about this Place, but the same token is not guaranteed to be returned for any given Place across different searches.
 */
@property (nonatomic, strong, readonly) NSString *reference;

/*!
 Contains a unique stable identifier denoting this place. This identifier may not be used to retrieve information about this place, but can be used to consolidate data about this Place, and to verify the identity of a Place across separate searches.
 */
@property (nonatomic, strong, readonly) NSString *identifier;

/*!
 Contains an array of NSRange (NSRange range = [matchedSubstrings[4] rangeValue];) indicating the matched substrings.
 Usually there is only one, but maybe there are more or nothing. Usuaful for painting that part in bold or another color.
 */
@property (nonatomic, strong, readonly) NSArray *matchedSubstrings;

/*!
 Your application's API key. This key identifies your application for purposes of quota management. Visit the APIs Console to select an API Project and obtain your key. Maps API for Business customers must use the API project created for them as part of their Places for Business purchase. Defaults to kGoogleAPIKey.
 */
@property (nonatomic, strong) NSString *key;

/*!
 Resolves the place to a CLPlacemark, issuing  Google Place Details request if needed.
 */
- (void)resolveToPlacemark:(SPGooglePlacesPlacemarkResultBlock)block;

@end
