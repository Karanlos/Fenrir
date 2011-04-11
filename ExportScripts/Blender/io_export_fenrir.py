import bpy

from io_utils import ExportHelper
from bpy.props import StringProperty, BoolProperty, EnumProperty

def writeData(context, filepath, use_some_setting):
    print("Running writeData")
    f = open(filepath, 'w')
    f.write("Hello World %s" % use_setting)
    f.close()
    
    return {'FINISHED'}

class FenrirExport(bpy.types.Operator, ExportHelper):
    bl_idname = "export.entity_data"
    bl_label = "Export Selected Mesh"
    
    filename_ext = ".fenent"
    
    use_setting = BoolProperty(name="Test Bool", description="Exmplate Tooltip", default=False)
    
    @classmethod
    def poll(cls, context):
        return context.active_object != None
    
    def execute(self, context):
        return writeData(context, self.filepath, self.use_setting)

def menu_func_export(self, context):
    self.layout.operator(FenrirExport.bl_idname, text="Export mesh, animation data to Fenrir engine")

def register():
    bpy.utils.register_class(FenrirExport)
    bpy.types.INFO_MT_file_export.append(menu_func_export)

def unregister():
    bpy.utils.unregister_class(FenrirExport)
    bpy.types.INFO_MT_file_export.remove(menu_func_export)


if __name__ == "__main__":
    register()
    
    #Test
    bpy.ops.export.entity_data('INVOKE_DEFAULT')