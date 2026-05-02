// Function : FUN_401654cc
// Address  : 0x401654cc
// Size     : 110 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_401654cc(undefined4 param_1)

{
  byte *pbVar1;
  undefined4 uVar2;
  int iVar3;
  
  pbVar1 = _DAT_3ffc1bb8;
  uVar2 = 0xffffffff;
  if (_DAT_3ffc1bb8 != (byte *)0x0) {
    iVar3 = (1 - (uint)*_DAT_3ffc1bb8) * 0x11c;
    if (_DAT_3ffc1bb8[iVar3 + 6] != 0) {
      (*(code *)&SUB_4008b3d0)
                (param_1,_DAT_3ffc1bb8 + (uint)_DAT_3ffc1bb8[iVar3 + 5] * 0x1c + iVar3 + 8,0x1c);
      if ((byte)(pbVar1[iVar3 + 5] + 1) == 10) {
        pbVar1[iVar3 + 5] = 0;
        memw();
      }
      else {
        pbVar1[iVar3 + 5] = pbVar1[iVar3 + 5] + 1;
        memw();
        memw();
      }
      pbVar1[iVar3 + 6] = pbVar1[iVar3 + 6] - 1;
      memw();
      uVar2 = 0;
    }
  }
  memw();
  return uVar2;
}

