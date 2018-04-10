/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IEntity.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouthie <jrouthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 11:31:10 by jrouthie          #+#    #+#             */
/*   Updated: 2018/01/14 16:26:30 by jrouthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IENTITY_HPP
# define IENTITY_HPP

# include <string>
# include <ncurses.h>
# include "Loger.hpp"

class Window;

class IEntity
{
public:
	virtual void update(Window &win) = 0;
    virtual void render(Window &win) = 0;
protected:
private:

};

#endif
