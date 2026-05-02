// Function : FUN_40128624
// Address  : 0x40128624
// Size     : 137 bytes


undefined4 FUN_40128624(undefined4 param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  *param_3 = 0;
  *param_2 = 0;
LAB_40128630:
  do {
    memw();
    iVar1 = FUN_40128a18();
    if ((iVar1 == 0) || (iVar2 = FUN_40128c5c(iVar1,param_1), iVar2 < 0)) {
      FUN_40128a7c(iVar1,0);
      goto LAB_4012864b;
    }
    iVar2 = FUN_40128c7c(iVar1,param_1);
    if (iVar2 == 1) {
      if (*param_2 != 0) {
LAB_401286a6:
        FUN_40128a7c(iVar1,0);
        goto LAB_40128699;
      }
      *param_2 = iVar1;
    }
    else {
      if ((iVar2 != -1) || (*param_3 != 0)) goto LAB_401286a6;
      *param_3 = iVar1;
LAB_40128699:
      if (*param_2 == 0) {
        memw();
        goto LAB_40128630;
      }
    }
    if (*param_3 != 0) {
      memw();
LAB_4012864b:
      if ((*param_2 == 0) || (uVar3 = 0, *param_3 == 0)) {
        FUN_40128a7c(*param_2,0);
        FUN_40128a7c(*param_3,0);
        *param_3 = 0;
        *param_2 = 0;
        uVar3 = 0xffffffff;
      }
      memw();
      return uVar3;
    }
  } while( true );
}

