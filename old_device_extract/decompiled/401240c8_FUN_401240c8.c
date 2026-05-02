// Function : FUN_401240c8
// Address  : 0x401240c8
// Size     : 140 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401240c8(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined2 uStack_64;
  undefined2 uStack_62;
  undefined1 auStack_56 [6];
  undefined1 auStack_50 [8];
  undefined2 uStack_48;
  undefined2 uStack_46;
  undefined1 auStack_44 [32];
  undefined4 *puStack_24;
  
  memw();
  memw();
  puStack_24 = _DAT_3ffc5708;
  memw();
  iVar1 = FUN_40102858(param_2 + 0x12,0x20);
  puVar2 = (undefined4 *)&DAT_3ffc5708;
  puVar3 = param_2;
  if (-1 < iVar1) goto LAB_40124103;
  do {
    param_1 = -1;
    while( true ) {
      puVar3 = puStack_24;
      memw();
      memw();
      puVar2 = (undefined4 *)*puVar2;
      if (puStack_24 == puVar2) {
        return;
      }
      (*(code *)&SUB_40082ec4)();
LAB_40124103:
      (*(code *)&SUB_4008b3d0)(auStack_56,param_1 + 0x5c,6);
      FUN_40104fb4(auStack_50);
      uStack_64 = SUB42(param_2,0);
      uStack_62 = (undefined2)((uint)param_2 >> 0x10);
      uStack_48 = uStack_64;
      uStack_46 = uStack_62;
      memw();
      memw();
      iVar1 = FUN_40102858(auStack_44,0x20);
      if (iVar1 < 0) break;
      memw();
      param_1 = FUN_40101d08(auStack_44,0x20,&DAT_3f41a7f0,auStack_56,0x12,puVar3 + 9,0x20);
      param_1 = param_1 >> 0x1f;
    }
  } while( true );
}

