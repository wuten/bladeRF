/*
 * This file is part of the bladeRF project
 *
 * Copyright (C) 2014  Nuand, LLC.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include "flash_common.h"
#include "cmd.h"

int flash_check_state(struct cli_state *s, const char *cmd_name)
{
    if (!cli_device_is_opened(s)) {
        return CMD_RET_NODEV;
    }

    if (cli_device_is_streaming(s)) {
        cli_err(s, cmd_name, "Flash operations require that the device is not "
                             "actively streaming.");

        /* Technically not the error, but we want to suppress the more generic
         * error message... */
        return CMD_RET_INVPARAM;
    }

    return 0;
}
