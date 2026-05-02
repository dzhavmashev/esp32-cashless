// Function : FUN_400df370
// Address  : 0x400df370
// Size     : 89 bytes


undefined8 FUN_400df370(undefined4 param_1,char *param_2)

{
  byte *pbVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (*param_2 == '\x04') {
    if (((byte)param_2[0x7b] < 0x28) && ((byte)param_2[0x7c] < 0x28)) {
      pbVar1 = (byte *)(param_2 + 0x7e);
      param_2 = (char *)0x0;
      if (((*pbVar1 & 0xdf) == 0x40) ||
         (param_2 = (char *)(uint)(*pbVar1 != 0x10), param_2 == (char *)0x0)) {
        uVar2 = 1;
      }
      else {
        uVar2 = 0;
        FUN_400f06a4(0x3ffc5490," TX:%d\n");
      }
    }
    else {
      FUN_400f06a4(0x3ffc5490,"d: %u)\n");
      uVar2 = 0;
    }
  }
  return CONCAT44(param_2,uVar2);
}

