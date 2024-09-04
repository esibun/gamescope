local steamdeck_lcd = {
    id = "steamdeck_lcd",
    pretty_name = "Steam Deck LCD",
    dynamic_refresh_rates = {
        40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
        50, 51, 52, 53, 54, 55, 56, 57, 58, 59,
        60
    },
    matches = function(vendor, product, model)
        --[[
        local blah = {
            { vendor = "WLC", model = "ANX7530 U" },
            { vendor = "ANX", model = "ANX7530 U" },
            { vendor = "VLV", model = "ANX7530 U" },
            { vendor = "VLV", model = "Jupiter" },
        }

        return { vendor = vendor, model = model } in blah
        ]]--
        return -1
    end
}
table.insert(gamescope.config.known_displays, steamdeck_lcd)
