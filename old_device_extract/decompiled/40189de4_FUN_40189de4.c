// Function : FUN_40189de4
// Address  : 0x40189de4
// Size     : 91 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40189de4(int *param_1,int param_2)

{
  int iVar1;
  
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    **(uint **)(param_2 + 0x2c) = **(uint **)(param_2 + 0x2c) | 0x20;
    iVar1 = *param_1;
    if (iVar1 == _DAT_3ffc8800) {
      memw();
      FUN_4018a258(iVar1,param_2,0);
      return;
    }
    (*(code *)*_DAT_3ffc87ec)(iVar1,param_2,0,0,param_1);
    return;
  }
  FUN_40147fe4(1,0x800,1,"",&DAT_3f423a5e,0x390);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

