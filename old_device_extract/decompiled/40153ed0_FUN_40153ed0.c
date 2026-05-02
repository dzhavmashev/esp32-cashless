// Function : FUN_40153ed0
// Address  : 0x40153ed0
// Size     : 183 bytes


undefined4 FUN_40153ed0(int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_1 == (int *)0x0) || (*param_1 == 0)) {
    FUN_40147fe4(1,0x800,1,"",&PTR_LAB_3f423ddc,0xd50);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (param_2 == 0x30) {
LAB_40153f55:
    iVar1 = FUN_40152804(param_1);
  }
  else if (param_2 < 0x31) {
    if (param_2 == 0x10) goto LAB_40153f55;
    if ((param_2 != 0x20) && (param_2 != 0)) goto LAB_40153f84;
    if (DAT_3ffc8a68 != '\0') {
      DAT_3ffc8a68 = '\0';
      memw();
      param_2 = 0x20;
    }
    memw();
    iVar1 = FUN_40152468(param_1,param_2);
  }
  else if (param_2 == 0xb0) {
    iVar1 = FUN_40152a8c(param_1,param_3);
  }
  else if (param_2 == 0xc0) {
    iVar1 = FUN_40152d2c(param_1);
  }
  else {
    if (param_2 != 0xa0) goto LAB_40153f84;
    iVar1 = FUN_40152db4(param_1);
  }
  if (iVar1 != 0) {
    FUN_40153a2c(param_1,iVar1,7,0);
    uVar2 = FUN_40152298(param_1,iVar1,param_2);
    return uVar2;
  }
LAB_40153f84:
  FUN_4015fb44(0);
  return 1;
}

