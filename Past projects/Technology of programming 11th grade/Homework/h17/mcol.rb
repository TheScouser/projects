class Song
  attr_accessor :name, :artist, :genre,:subgenre, :tags
  def initialize(name, artist, genre,subgenre,tags)
    @name   = name
    @artist = artist
    @genre  = genre
    @subgenre  = subgenre
    @tags = Array(tags)
  end

def add_artist_tag(artist)
  artist.keys.each do |key|
    if @artist==key
      artist[key].map {|a| @tags << a}
    end
  end
  return self
end

end

class Collection
	attr_accessor :songs,:songs_as_strings, :artist_tags

  def initialize(songs,artists)
    @songs = Array.new
    @songs_as_strings = songs.lines.to_a.map { |a| a.chomp}
    parse(artists)
   
  end

def parse(artists)
  songs_as_strings.map do |line|
  name, artist, genres, tags = line.split('.').map {|a| a.strip}
  genre, subgenre = genres.split(',').map {|b| b.strip}
  if !tags.nil? 
    tags = tags.split(',').map {|c| c.strip}
    tags << genre.downcase
  if !subgenre.nil?
    tags << subgenre.downcase
  end
@songs<<Song.new(name, artist, genre, subgenre, tags).add_artist_tag(artists)
  end
end

def find(criteria)
  criteria.keys.each do |key|
    if  key==:tags
      @songs= (find_song_by_tag(criteria[key]))
    elsif key==:artist
      @songs = (find_song_by_artist(criteria[key]))
    elsif key==:filter
      @songs = (filter(criteria[key]))
    end
  end
  return @songs
end

def filter(filter)
  return @songs.select{|s| filter[s]}
end

def find_song_by_artist(artist)
  return @songs.select{|s| s.artist == artist}
end

def find_song_by_tag(tags)
  if !tags.instance_of?(Array)
    tags=tags.split(',')
  end
songs = Array.new(@songs.select{|s| (s.tags & tags).count == tags.count})
return songs
end

end

dictionary={
  'John Coltrane' => %w[saxophone],
  'Bach' => %w[piano polyphony],
}

end
