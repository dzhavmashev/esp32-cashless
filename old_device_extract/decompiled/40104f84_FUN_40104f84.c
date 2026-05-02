// Function : FUN_40104f84
// Address  : 0x40104f84
// Size     : 44 bytes


undefined4 FUN_40104f84(int param_1,undefined1 *param_2,int param_3)

{
  int iVar1;
  undefined1 *puVar2;
  
  puVar2 = param_2 + param_3;
  while( true ) {
    if (param_2 == puVar2) {
      return 0;
    }
    iVar1 = FUN_40104f58(param_1);
    if (iVar1 < 0) break;
    *param_2 = (char)iVar1;
    memw();
    param_1 = param_1 + 2;
    param_2 = param_2 + 1;
    memw();
  }
  return 0xffffffff;
}

