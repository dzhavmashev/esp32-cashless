// Function : FUN_40128838
// Address  : 0x40128838
// Size     : 177 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40128838(undefined4 param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  byte abStack_67 [67];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  memw();
  uVar1 = FUN_401857ec(param_1);
  iVar2 = FUN_40128d5c(param_1);
  puVar3 = (undefined1 *)FUN_40128a18();
  iVar4 = FUN_40128a58(1);
  iVar5 = FUN_40128a90(uVar1,abStack_67 + 1,0x42,iVar2);
  if (-1 < iVar5) goto LAB_4012889c;
  do {
    iVar2 = -1;
    while( true ) {
      FUN_40128a7c(puVar3,0);
      FUN_40128a7c(iVar4,0);
      param_3 = iStack_24;
      param_2 = _DAT_3ffc5708;
      memw();
      memw();
      if (iStack_24 == _DAT_3ffc5708) {
        return;
      }
      (*(code *)&SUB_40082ec4)();
      puVar3 = &DAT_3ffc5708;
LAB_4012889c:
      if (((((abStack_67[iVar2] & 3) != 3) || (puVar3 == (undefined1 *)0x0)) || (iVar4 == 0)) ||
         ((iVar5 = FUN_40128ad8(uVar1,iVar4,puVar3), iVar5 < 0 ||
          (iVar5 = FUN_40128bd0(puVar3,2,puVar3), iVar5 < 0)))) break;
      iVar2 = FUN_40128b08(param_2,puVar3,uVar1,param_3);
      iVar2 = iVar2 >> 0x1f;
    }
  } while( true );
}

