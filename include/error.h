/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:35:53 by rmarceau          #+#    #+#             */
/*   Updated: 2023/04/21 12:23:06 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define ERROR_ARGS         "Error\nInvalid number of arguments (must be 1)"
# define ERROR_FILE         "Error\nMap file not found"
# define ERROR_EXTENSION    "Error\nMap invalid file extension (must be .ber)"
# define ERROR_PARSING      "Error\nMap parsing failed"
# define ERROR_ELEMENT      "Error\nElement in map is invalid"
# define ERROR_PLAYER 		"Error\nMap must have exactly 1 player"
# define ERROR_EXIT 		"Error\nMap must have exactly 1 exit"
# define ERROR_ITEM 		"Error\nMap must have at least 1 collectible"
# define ERROR_RECTANGLE 	"Error\nMap is not a rectangle or is not surrounded by walls"
# define ERROR_NEWLINE 		"Error\nMap must not be empty or have empty lines"
# define ERROR_PATH 		"Error\nNo valid path to finish the game"
# define ERROR_XPM 			"Error\nXPM load failed"
# define ERROR_IMG 			"Error\nImage creation failed"
# define ERROR_MLX 			"Error\nMLX initialization failed"
# define ERROR_MALLOC 		"Error\nMalloc failed"

#endif
