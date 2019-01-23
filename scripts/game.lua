configuration = { width = 1280, height = 768, title = "This is MakeIt sample" }

function game_startup()
	crate = Texture()
	crate:load("textures/crate.png")

	ball = Texture()
	ball:load("textures/ball.png")

	physics = Physics(10.0, 30.0)
	Physics.set_physics(physics)

	root = Scene()
	Scene.set_root(root)

	n = Node2D()
	n.name = "node"

	s1 = Sprite()
	s1:set_texture(crate)
	s1.z = 10
	s1.position = Vector2(100, 100)
	s1.name = "crate"
	n:add_child(s1)

	s2 = Sprite()
	s2:set_texture(ball)
	s2.z = -10
	s2.position = Vector2(200, 100)
	s2.name = "ball"
	n:add_child(s2)

	p = DynamicBody()
	shape = BoxShape(16.0, 16.0)
	p.set_shape(physics, shape)
	p.position = Vector2(100, 100)
	-- n.add_child(p)

	-- s3 = Sprite()
	-- s3:set_texture(crate)
	-- s3.name = "physics crate"
	-- p:add_child(s3)

	root:add_child(n)
	root:sort()

	x = 100
	rate = 0.05
end

function game_run(delta)
	x = x + rate / delta
	if x > 1180 then
		x = 100
	end
	s1.position = Vector2(x, 100)
end

function game_shutdown()
end
