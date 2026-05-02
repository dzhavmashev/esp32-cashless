// Function : FUN_4014b470
// Address  : 0x4014b470
// Size     : 100 bytes


void FUN_4014b470(int *param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_1 == (int *)0x0) {
    FUN_40147fe4(1,0x800,1,"",&DAT_3f423a5e,0x5d0);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  iVar1 = *param_1;
  if ((param_1[3] & 0x40U) != 0) {
    FUN_4014b430(param_1);
  }
  uVar3 = param_1[3];
  uVar2 = *(uint *)(iVar1 + 0x158);
  param_1[3] = uVar3 | 0x40;
  if (((uVar2 & 0x100000) != 0) && ((*(int *)(iVar1 + 0x14c) != 0 || (DAT_3ffc89ee != '\x01')))) {
    param_1[3] = uVar3 | 0xc40;
  }
  if ((uVar2 & 0x400000) != 0) {
    param_1[3] = param_1[3] | 0x80000;
  }
  memw();
  return;
}

