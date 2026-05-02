// Function : FUN_40102614
// Address  : 0x40102614
// Size     : 257 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_40102614(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined1 auStack_34 [8];
  undefined1 auStack_2c [8];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  memw();
  (*(code *)&SUB_4008b530)(param_5,0xa6,8);
  (*(code *)&SUB_4008b3d0)(param_5 + 8,param_4,param_3 << 3);
  iVar2 = FUN_40102184(param_1,param_2);
  uVar3 = 0xffffffff;
  if (iVar2 != 0) {
    iVar8 = 1;
    iVar4 = 6;
    do {
      iVar6 = 1;
      iVar5 = iVar8;
      while (iVar7 = param_5 + iVar6 * 8, iVar6 <= param_3) {
        iVar6 = iVar6 + 1;
        memw();
        (*(code *)&SUB_4008b3d0)(auStack_34,param_5,8);
        (*(code *)&SUB_4008b3d0)(auStack_2c,iVar7,8);
        FUN_401021b8(iVar2,auStack_34);
        (*(code *)&SUB_4008b3d0)(param_5,auStack_34,8);
        *(byte *)(param_5 + 7) = (byte)iVar5 ^ *(byte *)(param_5 + 7);
        memw();
        *(byte *)(param_5 + 6) = (byte)((uint)iVar5 >> 8) ^ *(byte *)(param_5 + 6);
        memw();
        *(byte *)(param_5 + 5) = (byte)((uint)iVar5 >> 0x10) ^ *(byte *)(param_5 + 5);
        uVar1 = (uint)iVar5 >> 0x18;
        iVar5 = iVar5 + 1;
        *(byte *)(param_5 + 4) = (byte)uVar1 ^ *(byte *)(param_5 + 4);
        memw();
        memw();
        (*(code *)&SUB_4008b3d0)(iVar7,auStack_2c,8);
      }
      iVar4 = iVar4 + -1;
      iVar8 = iVar8 + param_3;
    } while (iVar4 != 0);
    FUN_401021d0(iVar2);
    uVar3 = 0;
  }
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    (*(code *)&SUB_40082ec4)();
  }
  return uVar3;
}

