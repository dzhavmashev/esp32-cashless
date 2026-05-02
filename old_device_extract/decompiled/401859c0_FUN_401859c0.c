// Function : FUN_401859c0
// Address  : 0x401859c0
// Size     : 51 bytes


uint FUN_401859c0(int *param_1)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  
  if ((*(char *)(*param_1 + 4) != '\0') || (uVar3 = 0, 1 < param_1[1] - 1U)) {
    uVar3 = (uint)*(ushort *)(param_1 + 0x39);
    if ((param_1[0x11] != 0) &&
       ((uVar2 = (uint)*(ushort *)(param_1[0x11] + 0x268), uVar2 != 0 &&
        (bVar1 = uVar3 == 0, uVar3 = (uVar2 < uVar3) * uVar2 + (uVar2 >= uVar3) * uVar3, bVar1)))) {
      uVar3 = uVar2;
    }
  }
  return uVar3;
}

