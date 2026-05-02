// Function : FUN_4016c634
// Address  : 0x4016c634
// Size     : 100 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4016c634(undefined2 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  byte bVar2;
  undefined4 local_30;
  undefined4 uStack_2c;
  int iStack_28;
  
  iVar1 = 100;
  bVar2 = 0;
  do {
    (**(code **)(_DAT_3ffc7e64 + 0x14c))(1,param_1,&local_30);
    if ((iStack_28 < iVar1) || (bVar2 == 0)) {
      *param_3 = local_30;
      param_3[2] = iStack_28;
      param_3[1] = uStack_2c;
      if (iStack_28 < 0x30 && 1 < bVar2) {
        return;
      }
      iVar1 = iStack_28;
      if (iStack_28 < 0x24) {
        return;
      }
    }
    else if ((iVar1 < 0x30) && (1 < bVar2)) {
      return;
    }
    bVar2 = bVar2 + 1;
    if (bVar2 == 10) {
      return;
    }
  } while( true );
}

