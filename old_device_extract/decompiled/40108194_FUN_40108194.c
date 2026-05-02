// Function : FUN_40108194
// Address  : 0x40108194
// Size     : 112 bytes


void FUN_40108194(uint *param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  char cVar4;
  undefined4 uVar5;
  char *pcVar6;
  
  if (param_1 != (uint *)0x0) goto LAB_401081ac;
  pcVar6 = "!= NULL";
  uVar5 = 0x19b;
  while( true ) {
    (*(code *)&SUB_40094c54)("!= NULL",uVar5,"p_close",pcVar6);
LAB_401081ac:
    FUN_4011acdc(param_1 + 5);
    if (*(char *)((int)param_1 + 0xf) != '\0') break;
    pcVar6 = "ng == 0";
    uVar5 = 0x1a2;
  }
  cVar4 = *(char *)((int)param_1 + 0xf) + -1;
  *(char *)((int)param_1 + 0xf) = cVar4;
  memw();
  if ((cVar4 == '\0') && ((byte)param_1[4] != 0)) {
    param_3 = param_1[1];
    uVar2 = *param_1;
    param_1[1] = 0;
    *param_1 = 0;
    uVar1 = 1;
    uVar3 = (byte)param_1[4] & 1;
  }
  else {
    uVar1 = 0;
    uVar2 = uVar1;
    uVar3 = uVar1;
  }
  memw();
  FUN_4011ad00(param_1 + 5);
  if (uVar1 != 0) {
    FUN_40108020(uVar3,uVar2,param_3);
  }
  return;
}

