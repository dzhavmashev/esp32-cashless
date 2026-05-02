// Function : FUN_400e979c
// Address  : 0x400e979c
// Size     : 57 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_400e979c(void)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 auStack_74 [44];
  undefined1 uStack_48;
  undefined4 *puStack_24;
  
  memw();
  memw();
  puStack_24 = _DAT_3ffc5708;
  iVar2 = FUN_400e81d0();
  puVar3 = (undefined4 *)&DAT_3ffc5708;
  if (iVar2 != 0) goto LAB_400e97c5;
  do {
    uVar1 = 0;
    do {
      memw();
      memw();
      puVar3 = (undefined4 *)*puVar3;
      if (puStack_24 == puVar3) {
        return uVar1;
      }
      func_0x40082ecc();
LAB_400e97c5:
      iVar2 = FUN_401470a4(auStack_74);
      uVar1 = uStack_48;
    } while (iVar2 == 0);
  } while( true );
}

