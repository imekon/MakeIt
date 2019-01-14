configuration = { width = 1280, height = 800, title = "This is MakeIt sample" }

running = false

function game_startup()
	t = Texture.load("textures/red.png")
	s = Sprite.create()
	Sprite.set_texture(s, t)
end

function game_run()
end

function game_shutdown()
end
