Rails.application.routes.draw do
  # For details on the DSL available within this file, see http://guides.rubyonrails.org/routing.html
  post 'signup', to: 'users#create'
  post 'auth/login', to: 'authentication#authenticate'

  scope module: :v2, constraints: ApiVersion.new('v2') do
  	resources :todos, only: :index
  end

  scope module: :v1, constraints: ApiVersion.new('v1', true) do
  	resources :todos do
	  	resources :items
	 end
  end

end