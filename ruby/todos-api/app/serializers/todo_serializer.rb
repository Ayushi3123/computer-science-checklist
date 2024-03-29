class TodoSerializer
  include FastJsonapi::ObjectSerializer
  attributes :id, :title, :created_by, :created_at, :updated_at

  has_many :items
end
