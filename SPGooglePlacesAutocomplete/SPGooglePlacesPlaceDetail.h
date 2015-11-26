//
//  SPGooglePlacesPlaceDetail.h
//  SPGooglePlacesAutocompleteDemo
//
//  Created by Ricardo Ruiz Lopez on 25/11/2015.
//  Copyright © 2015 tickbox.com.au. All rights reserved.
//

/*
{
    "address_components" =     (
                                {
                                    "long_name" = London;
                                    "short_name" = London;
                                    types =             (
                                                         locality,
                                                         political
                                                         );
                                },
                                {
                                    "long_name" = "Laurel County";
                                    "short_name" = "Laurel County";
                                    types =             (
                                                         "administrative_area_level_2",
                                                         political
                                                         );
                                },
                                {
                                    "long_name" = Kentucky;
                                    "short_name" = KY;
                                    types =             (
                                                         "administrative_area_level_1",
                                                         political
                                                         );
                                },
                                {
                                    "long_name" = "United States";
                                    "short_name" = US;
                                    types =             (
                                                         country,
                                                         political
                                                         );
                                }
                                );
    "adr_address" = "<span class=\"locality\">London</span>, <span class=\"region\">KY</span>, <span class=\"country-name\">USA</span>";
    "formatted_address" = "London, KY, USA";
    geometry =     {
        location =         {
            lat = "37.1289771";
            lng = "-84.08326459999999";
        };
        viewport =         {
            northeast =             {
                lat = "37.1522599";
                lng = "-84.03595709999999";
            };
            southwest =             {
                lat = "37.0797589";
                lng = "-84.126262";
            };
        };
    };
    icon = "https://maps.gstatic.com/mapfiles/place_api/icons/geocode-71.png";
    id = 692adb38e4db9759599d6f73f300a3bba7db714a;
    name = London;
    "place_id" = "ChIJA8c2lxTNXIgRmMwHc-RRGWI";
    reference = "CnRsAAAAl86L-RXvnp6PcWJv6k76zn7oEZetCqtzMP5JYeLa6GBrIHy1JKPVDj4szlUlYjkkxmlYR4K51e3S6C2mVtgkMUQo8u8VCcCfcsDghOhE0tyoSXqS3Qnj_EkeADVDB2_S1kJj5y5QCmh2RypbugZbmBIQRLEExYvi_x9H-YES3bk7DBoUuoaW193voIUcjTV-dZgyp0H3_aE";
    scope = GOOGLE;
    types =     (
                 locality,
                 political
                 );
    url = "https://maps.google.com/?q=London,+KY,+USA&ftid=0x885ccd149736c703:0x621951e47307cc98";
    vicinity = London;
}
*/

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@interface SPGooglePlacesPlaceDetail : NSObject

/*!
 Contains the human-readable name for the returned result. For establishment results, this is usually the business name.
 */
@property (nonatomic, strong, readonly) NSString *name;

/*!
 Contains the address.
 */
@property (nonatomic, strong, readonly) NSString *formattedAddress;

/*!
 Contains a unique token that you can use to retrieve additional information about this place in a Place Details request. You can store this token and use it at any time in future to refresh cached data about this Place, but the same token is not guaranteed to be returned for any given Place across different searches.
 */
@property (nonatomic, strong, readonly) NSString *reference;

/*!
 Contains a unique stable identifier denoting this place. This identifier may not be used to retrieve information about this place, but can be used to consolidate data about this Place, and to verify the identity of a Place across separate searches.
 */
@property (nonatomic, strong, readonly) NSString *identifier;

/*!
 Contains the location of this place.
 */
@property (nonatomic, strong, readonly) CLLocation *location;

/*!
 Your application's API key. This key identifies your application for purposes of quota management. Visit the APIs Console to select an API Project and obtain your key. Maps API for Business customers must use the API project created for them as part of their Places for Business purchase.
 */
@property (nonatomic, strong, readonly) NSString *key;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithPlaceDetailsFromDictionary:(NSDictionary *)dictionary apiKey:(NSString *)apiKey NS_DESIGNATED_INITIALIZER;
+ (instancetype)placeDetailsFromDictionary:(NSDictionary *)dictionary apiKey:(NSString *)apiKey;

@end
