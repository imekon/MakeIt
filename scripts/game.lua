configuration = { width = 1280, height = 800, title = "This is MakeIt sample" }

running = false

function game_startup()
	print("startup")
end

function game_run()
	if not running then
		print("running")
		running = true
	end
end

function game_shutdown()
end
