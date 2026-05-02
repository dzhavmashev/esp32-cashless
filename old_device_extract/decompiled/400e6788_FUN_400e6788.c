// Function : FUN_400e6788
// Address  : 0x400e6788
// Size     : 150 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_400e6788(undefined4 *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_34 [16];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  iVar1 = FUN_400ecfa8(*param_1,param_2);
  if (iVar1 != 0) goto LAB_400e67be;
  do {
    iVar1 = 0;
    while( true ) {
      param_3 = iStack_24;
      param_2 = _DAT_3ffc5708;
      memw();
      memw();
      if (iStack_24 == _DAT_3ffc5708) {
        return iVar1;
      }
      func_0x40082ecc();
LAB_400e67be:
      iVar2 = FUN_400ed1b4(*param_1,param_2);
      if (iVar2 == 0) break;
      iVar3 = (*(code *)&LAB_40170346_2)(iVar2 + 1);
      iVar2 = FUN_400ed234(*param_1,param_2,iVar3,iVar2);
      *(undefined1 *)(iVar3 + iVar2) = 0;
      FUN_400f0be8(auStack_34,iVar3);
      FUN_400f0d60(param_3,auStack_34);
      FUN_400f0a50(auStack_34);
      FUN_4016fffc(iVar3);
    }
  } while( true );
}

