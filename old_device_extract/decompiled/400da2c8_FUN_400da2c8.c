// Function : FUN_400da2c8
// Address  : 0x400da2c8
// Size     : 39 bytes


void FUN_400da2c8(undefined4 *param_1)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  
  if ((param_1[4] == 1) && (iVar3 = FUN_400dbf24(*param_1), iVar3 != 0)) {
    cVar1 = FUN_400e979c(&DAT_3ffc516c);
    param_1[0xc] = (int)cVar1;
  }
  uVar2 = FUN_400da298(param_1);
  *(undefined1 *)(param_1 + 7) = uVar2;
  return;
}

