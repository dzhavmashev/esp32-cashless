// Function : FUN_40164da8
// Address  : 0x40164da8
// Size     : 171 bytes


undefined1 FUN_40164da8(uint *param_1)

{
  undefined1 uVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_1 == (uint *)0x0) {
    FUN_40147fe4(6,0x200,1," %s %u\n");
    memw();
    FUN_40147fe4(6,0x800,1,"lags=%x",&DAT_3f42470c,&DAT_3f424870,0x6c8);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  uVar2 = (uint)*(byte *)((int)param_1 + 5);
  if ((4 < uVar2) && ((*param_1 & 0x8000000) != 0)) {
    return 1;
  }
  if (param_1[7] == 0) {
    memw();
    FUN_40147fe4(6,0x200,1," %s %u\n",param_1[4] >> 0x13 & 1,param_1[1] & 0xf,*param_1);
    memw();
    FUN_40147fe4(6,0x800,1," no mem",&DAT_3f42470c,&DAT_3f424870,0x6d3);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  uVar3 = (uint)*(byte *)(param_1[7] + 8);
  if (DAT_3ffc1a44 == '\0') {
    uVar1 = 1;
    if (uVar2 < uVar3) {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 1;
    if (uVar2 < (uint)(0xb < uVar3) * 0xb + (0xb >= uVar3) * uVar3) {
      uVar1 = 0;
    }
  }
  return uVar1;
}

