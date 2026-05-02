// Function : FUN_40129afc
// Address  : 0x40129afc
// Size     : 201 bytes


void FUN_40129afc(int *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined8 uVar6;
  
  if (*(char *)(*param_1 + 0xb) != '\0') {
    iVar4 = param_1[0x1a];
    uVar2 = (uint)CONCAT11(*(undefined1 *)(iVar4 + 2),*(undefined1 *)(iVar4 + 3));
    uVar1 = (uint)*(byte *)(iVar4 + 7) | (uint)*(byte *)(iVar4 + 4) << 0x18 |
            (uint)*(byte *)(iVar4 + 5) << 0x10 | (uint)*(byte *)(iVar4 + 6) << 8;
    uVar3 = param_1[0x27];
    uVar5 = param_1[0x26];
    if ((uVar3 < uVar2) || ((uVar2 == uVar3 && (uVar5 < uVar1)))) {
      if ((uVar2 - uVar3 == (uint)(uVar1 < uVar1 - uVar5)) && (uVar1 - uVar5 < 0x40)) {
        uVar6 = (*(code *)&SUB_4000c818)(param_1[0x28],param_1[0x29]);
        iVar4 = (int)((ulonglong)uVar6 >> 0x20);
        uVar3 = (uint)uVar6 | 1;
      }
      else {
        uVar3 = 1;
        iVar4 = 0;
      }
      param_1[0x28] = uVar3;
      param_1[0x29] = iVar4;
      param_1[0x26] = uVar1;
      param_1[0x27] = uVar2;
    }
    else if ((uVar3 - uVar2 == (uint)(uVar5 < uVar5 - uVar1)) && (uVar5 - uVar1 < 0x40)) {
      uVar6 = (*(code *)&SUB_4000c818)(1,0);
      param_1[0x28] = param_1[0x28] | (uint)uVar6;
      param_1[0x29] = param_1[0x29] | (uint)((ulonglong)uVar6 >> 0x20);
      memw();
    }
  }
  memw();
  return;
}

