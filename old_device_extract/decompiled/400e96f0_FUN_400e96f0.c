// Function : FUN_400e96f0
// Address  : 0x400e96f0
// Size     : 66 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_400e96f0(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined1 auStack_74 [80];
  undefined4 *puStack_24;
  
  memw();
  memw();
  puStack_24 = _DAT_3ffc5708;
  iVar1 = FUN_400e81d0();
  puVar3 = (undefined4 *)&DAT_3ffc5708;
  if (iVar1 != 0) goto LAB_400e9719;
  do {
    uVar2 = 0;
    while( true ) {
      memw();
      memw();
      puVar3 = (undefined4 *)*puVar3;
      if (puStack_24 == puVar3) {
        return uVar2;
      }
      func_0x40082ecc();
LAB_400e9719:
      iVar1 = FUN_401470a4(auStack_74);
      if (iVar1 != 0) break;
      uVar2 = 0x3ffc51b9;
      func_0x4008b3d8(0x3ffc51b9,auStack_74,6);
    }
  } while( true );
}

