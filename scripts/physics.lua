function setup_physics()
	crate = Texture()
	crate:load("textures/crate.png")

	ball = Texture()
	ball:load("textures/ken.png")

	floor_texture = Texture()
	floor_texture:load("textures/floor.png")

	physics = Physics(10.0, 30.0)
	-- physics.debug = true

	root = Scene()
	Scene.set_root(root)

	node = Node2D()
	node.name = "ROOT"

	s1 = Sprite()
	s1:set_texture(crate)
	s1.z = 10
	s1.position = Vector2(100, 100)
	s1.name = "crate"
	node:add_child(s1)

	s2 = Sprite()
	s2:set_texture(ball)
	s2.z = -10
	s2.position = Vector2(200, 100)
	s2.name = "ball"
	node:add_child(s2)

	floor = StaticBody()
	floor.position = Vector2(640, 597)
	floor.name = "physics floor"
	shape2 = BoxShape(1280, 10)
	floor:set_shape(shape2)

	floor_sprite = Sprite()
	floor_sprite:set_texture(floor_texture)
	floor:add_child(floor_sprite)
	node:add_child(floor)

	root:add_child(node)
	root:sort()
end

function create_crate(x, y)
	local p = DynamicBody()
	p.friction = 0.3
	p.restitution = 0.3
	local shape = BoxShape(64, 64)
	p:set_shape(shape)
	p.position = Vector2(x, y)
	node:add_child(p)

	local s = Sprite()
	s:set_texture(crate)
	p:add_child(s)

	return p
end

function create_ball(x, y)
	local p = DynamicBody()
	p.friction = 0.3
	p.restitution = 0.7
	local shape = CircleShape(16)
	p:set_shape(shape)
	p.position = Vector2(x, y)
	node:add_child(p)

	local s = Sprite()
	s:set_texture(ball)
	p:add_child(s)
	return p
end

function create_static_crate(x, y)
	local p = StaticBody()
	local shape = BoxShape(64, 64)
	p:set_shape(shape)
	p.position = Vector2(x, y)
	node:add_child(p)

	local s = Sprite()
	s:set_texture(crate)
	p:add_child(s)

	return p
end

function create_crates()
	for i = 1, 8 do
		create_crate(300 + i * 72, 100)
	end

	local p = create_crate(400, 200)
	p.rotate = 30
end

function create_end_stops()
	create_static_crate(100, 560 - 128)
	create_static_crate(100, 560 - 64)
	create_static_crate(100, 560)
	create_static_crate(550, 560)
	create_static_crate(1000, 560)
	create_static_crate(1000, 560 - 64)
	create_static_crate(1000, 560 - 128)
end

function create_balls()
	for i = 1, 10 do
		local b = create_ball(160 + i * 50, 200)
		if i == 5 then
			b.rotate = 30
		end
	end
end