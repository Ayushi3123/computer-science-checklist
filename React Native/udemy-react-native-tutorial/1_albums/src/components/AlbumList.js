import React, { Component } from 'react';
import { View, ScrollView } from 'react-native';
import axios from 'axios';
import AlbumDetail from './AlbumDetail';

class AlbumList extends Component {
    state = {
        albums: []
    };

    render() {

        console.log(this.state);

        return (
            <ScrollView>
                {this.renderAlbums()}
            </ScrollView>
        );
    }
    
    renderAlbums() {
        return this.state.albums.map(album => {
            return <AlbumDetail key={album.title} album={album} />
        });
    }

    componentWillMount() {
        axios.get('https://rallycoding.herokuapp.com/api/music_albums').then(res => {
            this.setState({
                albums: res.data
            });
        }).catch(err => {
            console.log(err);
        });
    }
}

export default AlbumList;