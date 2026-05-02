// Function : FUN_4012c940
// Address  : 0x4012c940
// Size     : 44 bytes


uint FUN_4012c940(int *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = FUN_4012b4f8(*(undefined1 *)(*param_1 + 8));
  if ((undefined1 *)param_1[0xe] != (undefined1 *)0x0) {
    uVar2 = FUN_4012b4f8(*(undefined1 *)param_1[0xe]);
    uVar1 = (uVar1 < uVar2) * uVar1 + (uVar1 >= uVar2) * uVar2;
  }
  if ((undefined1 *)param_1[0x10] != (undefined1 *)0x0) {
    uVar2 = FUN_4012b4f8(*(undefined1 *)param_1[0x10]);
    uVar1 = (uVar1 < uVar2) * uVar1 + (uVar1 >= uVar2) * uVar2;
  }
  return uVar1;
}

