// Function : FUN_4013cee0
// Address  : 0x4013cee0
// Size     : 102 bytes


/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_4013cee0(char *param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  
  memw();
  if (*param_1 == param_1[1]) {
    uVar4 = *param_2;
    uVar3 = param_2[1];
    uVar1 = param_2[3];
    uVar2 = param_2[2];
    FUN_4016886c(param_2,param_3);
    if (*param_3 != uVar4) {
      return 0;
    }
    if (param_3[1] != uVar3) {
      return 0;
    }
    if (param_3[2] != uVar2) {
      return 0;
    }
    if (param_3[3] != uVar1) {
      return 0;
    }
    (*(code *)&SUB_4008b530)(param_3,0,0x10);
    FUN_4013ae54(param_3,0x10);
    uVar6 = (*(code *)&SUB_40094bc8)();
    uVar5 = (undefined4)((ulonglong)uVar6 >> 0x20);
    param_3 = (uint *)uVar6;
    cust0();
    if ((uVar4 & 1 << ((byte)uVar1 & 0x1f)) != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  }
  else {
    uVar5 = 0x10;
  }
  FUN_4013ae54(param_3,uVar5);
  return 0xffffffde;
}

