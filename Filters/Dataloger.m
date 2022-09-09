function Dataloger
set_param('stm32f4discovery_mic_DataLoger','SimulationCommand', 'start');
    %%a = sim('stm32f4discovery_mic_DataLoger','SimulationMode','External');
    b = a.get('simout')
    assignin('base','b',b);
end