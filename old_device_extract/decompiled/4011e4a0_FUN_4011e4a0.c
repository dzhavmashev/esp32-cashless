// Function : FUN_4011e4a0
// Address  : 0x4011e4a0
// Size     : 184 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_4011e4a0(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined8 uVar7;
  
  (*(code *)&SUB_40092a70)();
  (*(code *)&SUB_40092a98)(0x3ffbe100,0xffffffff);
  uVar1 = _DAT_3ff48050;
  memw();
  if (_DAT_3ff48050 == 0) {
    _DAT_50000208 = 0;
    _DAT_5000020c = 0;
    _DAT_50000200 = 0;
    _DAT_50000204 = 0;
  }
  memw();
  uVar7 = (*(code *)&SUB_4008e0c0)();
  uVar3 = (uint)uVar7 - _DAT_50000200;
  uVar4 = (uint)((ulonglong)uVar3 * (ulonglong)uVar1 >> 0x20);
  uVar2 = ((int)((ulonglong)uVar7 >> 0x20) - _DAT_50000204) - (uint)((uint)uVar7 < uVar3);
  uVar5 = uVar2 * uVar1;
  uVar6 = uVar4 << 0xd | uVar3 * uVar1 >> 0x13;
  uVar3 = uVar6 + uVar5 * 0x2000;
  _DAT_50000208 = uVar3 + _DAT_50000208;
  _DAT_5000020c =
       (uint)(_DAT_50000208 < uVar3) +
       (uint)(uVar3 < uVar6) +
       (uVar4 >> 0x13) + (uVar5 >> 0x13 | (int)((ulonglong)uVar2 * (ulonglong)uVar1 >> 0x20) << 0xd)
       + _DAT_5000020c;
  memw();
  _DAT_50000200 = uVar7;
  (*(code *)&SUB_40092a70)();
  (*(code *)&SUB_40092bec)(0x3ffbe100);
  return CONCAT44(_DAT_5000020c,_DAT_50000208);
}

