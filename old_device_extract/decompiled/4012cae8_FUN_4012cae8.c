// Function : FUN_4012cae8
// Address  : 0x4012cae8
// Size     : 125 bytes


void FUN_4012cae8(int *param_1)

{
  char cVar1;
  code *pcVar2;
  int iVar3;
  
  cVar1 = *(char *)(param_1[0x11] + 2);
  if (param_1[2] == 1) {
    param_1[2] = 2;
    param_1[3] = 0;
  }
  if (param_1[0xf] != 0) {
    *(undefined4 *)(param_1[0x10] + 0x7c) = *(undefined4 *)(param_1[0xf] + 0x7c);
    memw();
    FUN_4012cacc();
    FUN_4013ae44(param_1[0xf]);
  }
  iVar3 = param_1[0x10];
  param_1[0x10] = 0;
  pcVar2 = *(code **)(*param_1 + 0x58);
  param_1[0xf] = iVar3;
  if (((pcVar2 != (code *)0x0) && (*(int *)(iVar3 + 0x10) != 0)) && (cVar1 == '\0')) {
    memw();
    (*pcVar2)(*(undefined4 *)(*param_1 + 0x5c));
  }
  if ((*(char *)(*param_1 + 5) == '\x01') && (*(int *)(param_1[0x11] + 0x24c) != 0)) {
    FUN_40185804(param_1,0);
  }
  else {
    FUN_4012ca94(param_1);
  }
  param_1[1] = param_1[1] + 1;
  memw();
  return;
}

