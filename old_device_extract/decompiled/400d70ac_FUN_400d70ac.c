// Function : FUN_400d70ac
// Address  : 0x400d70ac
// Size     : 190 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400d70ac(undefined4 param_1)

{
  undefined4 uVar1;
  byte *pbVar2;
  int iVar3;
  byte local_55 [7];
  undefined1 uStack_4e;
  byte bStack_4d;
  undefined1 uStack_4c;
  undefined1 uStack_4b;
  undefined1 uStack_4a;
  undefined1 uStack_49;
  undefined1 uStack_48;
  undefined1 uStack_47;
  undefined1 uStack_46;
  undefined1 auStack_45 [33];
  int iStack_24;
  
  pbVar2 = local_55;
  memw();
  iVar3 = 0;
  memw();
  iStack_24 = _DAT_3ffc5708;
  do {
    uVar1 = func_0x40084304();
    *pbVar2 = (byte)((uint)uVar1 >> 0x18);
    pbVar2[1] = (byte)((uint)uVar1 >> 0x10);
    pbVar2[2] = (byte)((uint)uVar1 >> 8);
    pbVar2[3] = (byte)uVar1;
    iVar3 = iVar3 + 4;
    pbVar2 = pbVar2 + 4;
  } while (iVar3 != 0x10);
  FUN_401742a0(auStack_45,0x21,"r state",local_55[0],local_55[1],local_55[2],local_55[3],local_55[4]
               ,local_55[5],local_55[6] & 0xf | 0x40,uStack_4e,bStack_4d & 0x3f | 0x80,uStack_4c,
               uStack_4b,uStack_4a,uStack_49,uStack_48,uStack_47,uStack_46);
  FUN_400f0be8(param_1,auStack_45);
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    func_0x40082ecc();
  }
  return;
}

