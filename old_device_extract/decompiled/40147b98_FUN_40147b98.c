// Function : FUN_40147b98
// Address  : 0x40147b98
// Size     : 110 bytes


int FUN_40147b98(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  if (param_1 == 0) {
    FUN_40147fe4(1,0x800,1,"",&DAT_3f4239c1,0x69);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if ((**(uint **)(param_2 + 0x2c) & 2) == 0) {
    uVar1 = (uint)*(byte *)(param_1 + 0x134);
    uVar4 = 0;
  }
  else {
    uVar1 = (uint)*(byte *)(param_1 + 0x135);
    uVar4 = uVar1 + 1;
    if (1 < uVar1) {
      uVar4 = uVar1 - 1;
    }
    uVar4 = uVar4 & 0xff;
  }
  iVar2 = *(int *)(&DAT_3ffc8930 + uVar1 * 4);
  if ((iVar2 != 0) && (*(int *)(iVar2 + 0xa0) != 0)) {
    iVar3 = (**(code **)(*(int *)(iVar2 + 0xa0) + 0x10))(iVar2,param_2,(uVar4 & 3) << 6);
    if (iVar3 != 0) {
      return iVar2;
    }
  }
  return 0;
}

