// Function : FUN_40109e04
// Address  : 0x40109e04
// Size     : 75 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40109e04(undefined4 param_1,undefined4 param_2,int *param_3)

{
  undefined4 uVar1;
  char *pcVar2;
  undefined4 in_t0;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  
  if (*param_3 != 0) goto LAB_40109e20;
  pcVar2 = "id mbox";
  uVar1 = 0x1c6;
  param_1 = in_t0;
  while( true ) {
    (*(code *)&SUB_40094c54)("message",uVar1,"pi_call",pcVar2);
    in_t0 = param_1;
LAB_40109e20:
    if (_DAT_3ffc5ccc != 0) break;
    pcVar2 = "tcpip.c";
    uVar1 = 0x1c7;
    param_1 = in_t0;
  }
  local_30 = 0;
  memw();
  uStack_2c = param_1;
  uStack_28 = param_2;
  FUN_4011ae80(&DAT_3ffc5ccc,&local_30);
  FUN_4011ade8(param_3,0);
  return;
}

