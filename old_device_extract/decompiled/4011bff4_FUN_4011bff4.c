// Function : FUN_4011bff4
// Address  : 0x4011bff4
// Size     : 30 bytes


char FUN_4011bff4(undefined4 param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = FUN_4011b0b4();
  *(undefined4 *)(param_2 + 0x24) = uVar2;
  memw();
  cVar1 = FUN_40109e04(param_1,param_2,uVar2);
  if (cVar1 == '\0') {
    cVar1 = *(char *)(param_2 + 4);
  }
  return cVar1;
}

