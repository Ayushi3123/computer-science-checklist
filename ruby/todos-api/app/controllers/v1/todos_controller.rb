module V1
	class TodosController < ApplicationController
		before_action :set_todo, only: [:show, :update, :destroy]

		def index
			@todos = current_user.todos.paginate(page: params[:page], per_page: 20)
			json_response(TodoSerializer.new(@todos).serializable_hash)
		end

		def create
			@todo = current_user.todos.create!(todo_params)
			json_response(@todo, :created)
		end

		def show
			json_response(@todo)
		end

		def update
			@todo.update(todo_params)
			head :no_content
		end

		def destroy
			@todo.destroy
			head :no_content
		end

		private

		def todo_params
			params.permit(:title)
		end

		def set_todo
			@todo = current_user.todos.find(params[:id])
		end
	end
end