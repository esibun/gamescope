local steamdeck_oled_hdr = {
    supported = true,
    force_enabled = true,
    eotf = gamescope.eotf.gamma22,
    max_content_light_level = 1000,
    max_frame_average_luminance = 800,
    min_content_light_level = 0,
}

local steamdeck_oled_refresh_rates = {
    45, 47, 48, 49,
    50, 51, 53, 55, 56, 59,
    60, 62, 64, 65, 66, 68,
    72, 73, 76, 77, 78,
    80, 81, 82, 84, 85, 86, 87, 88,
    90
}

local steamdeck_oled_sdc = {
    id = "steamdeck_oled_sdc",
    pretty_name = "Steam Deck OLED (SDC)",
    hdr = steamdeck_oled_hdr,
    dynamic_refresh_rates = steamdeck_oled_refresh_rates,
    matches = function(vendor, product, model)
        return -1
    end
}
table.insert(gamescope.config.known_displays, steamdeck_oled_boe)

local steamdeck_oled_boe = {
    id = "steamdeck_oled_boe",
    pretty_name = "Steam Deck OLED (BOE)",
    hdr = steamdeck_oled_hdr,
    dynamic_refresh_rates = steamdeck_oled_refresh_rates,
    matches = function(vendor, product, model)
        return -1
    end
}
table.insert(gamescope.config.known_displays, steamdeck_oled_boe)
