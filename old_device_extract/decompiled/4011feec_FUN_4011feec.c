// Function : FUN_4011feec
// Address  : 0x4011feec
// Size     : 100 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4011feec(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined1 auStack_28 [40];
  
  FUN_40177b4c(auStack_28,0);
  FUN_4011fdf8(auStack_28,0);
  uVar4 = FUN_4011e4a0();
  uVar5 = (*(code *)&SUB_40085b74)();
  uVar6 = FUN_4011fe98();
  uVar1 = (uint)uVar4 - (int)uVar5;
  uVar2 = _DAT_3ffc6d18 - uVar1;
  uVar3 = uVar2 + (int)uVar6;
  FUN_4011fe6c(uVar3,(uint)(uVar3 < uVar2) +
                     ((_DAT_3ffc6d1c -
                      (((int)((ulonglong)uVar4 >> 0x20) - (int)((ulonglong)uVar5 >> 0x20)) -
                      (uint)((uint)uVar4 < uVar1))) - (uint)(_DAT_3ffc6d18 < uVar2)) +
                     (int)((ulonglong)uVar6 >> 0x20));
  return;
}

