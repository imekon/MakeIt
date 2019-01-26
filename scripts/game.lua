configuration = { width = 1280, height = 768, title = "This is MakeIt sample" }

function game_startup()
	crate = Texture()
	crate:load("textures/crate.png")

	ball = Texture()
	ball:load("textures/ball.png")

	physics = Physics(10.0, 30.0)
	-- physics.debug = true

	root = Scene()
	Scene.set_root(root)

	node = Node2D()
	node.name = "node"

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

	for i = 1,3 do
		local p = DynamicBody()
		p.position = Vector2(300 + i * 64, 100)
		local shape = BoxShape(16.0, 16.0)
		p:set_shape(shape)
		node:add_child(p)

		local s = Sprite()
		s:set_texture(crate)
		p:add_child(s)
	end

	-- floor = StaticBody()
	-- floor.name = "physics floor"
	-- shape2 = BoxShape(1280, 10)
	-- floor:set_shape(shape2)
	-- floor.position = Vector2(0, 600)
	-- node:add_child(floor)

	root:add_child(node)
	root:sort()

	x = 100
	rate = 0.05
end

function game_run(delta)
	-- x = x + rate / delta
	-- if x > 1180 then
	--	x = 100
	-- end
	-- s1.position = Vector2(x, 100)
end

function game_shutdown()
end
