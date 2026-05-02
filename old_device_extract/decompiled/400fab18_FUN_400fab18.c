// Function : FUN_400fab18
// Address  : 0x400fab18
// Size     : 48 bytes


undefined4 FUN_400fab18(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0x1107;
  if ((*(char *)(param_1 + 0x12) != '\0') && (uVar2 = 0x1104, *(char *)(param_1 + 0x11) == '\0')) {
    iVar1 = (*(code *)&SUB_4008c01c)(param_3);
    uVar2 = FUN_400fa29c(*(undefined4 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 0x10),0x21,param_2
                         ,param_3,iVar1 + 1);
  }
  return uVar2;
}

