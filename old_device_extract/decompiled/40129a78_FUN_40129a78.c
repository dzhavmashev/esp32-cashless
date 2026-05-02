// Function : FUN_40129a78
// Address  : 0x40129a78
// Size     : 128 bytes


int FUN_40129a78(int *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar3 = 0;
  if (*(char *)(*param_1 + 0xb) != '\0') {
    iVar3 = param_1[0x1a];
    uVar1 = (uint)CONCAT11(*(undefined1 *)(iVar3 + 2),*(undefined1 *)(iVar3 + 3));
    uVar5 = (uint)*(byte *)(iVar3 + 7) | (uint)*(byte *)(iVar3 + 4) << 0x18 |
            (uint)*(byte *)(iVar3 + 5) << 0x10 | (uint)*(byte *)(iVar3 + 6) << 8;
    uVar2 = param_1[0x27];
    uVar4 = param_1[0x26];
    if ((uVar2 < uVar1) || ((uVar1 == uVar2 && (uVar4 < uVar5)))) {
      iVar3 = 0;
    }
    else {
      uVar5 = uVar4 - uVar5;
      if ((uVar2 - uVar1 == (uint)(uVar4 < uVar5)) && (uVar5 < 0x40)) {
        uVar1 = (*(code *)&SUB_4000c84c)(param_1[0x28],param_1[0x29]);
        iVar3 = -(uVar1 & 1);
      }
      else {
        iVar3 = -1;
      }
    }
  }
  return iVar3;
}

