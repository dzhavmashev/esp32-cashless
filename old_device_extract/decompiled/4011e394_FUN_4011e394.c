// Function : FUN_4011e394
// Address  : 0x4011e394
// Size     : 263 bytes


void FUN_4011e394(uint *param_1,uint param_2,uint *param_3)

{
  undefined4 extraout_a3;
  uint *puVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  char *pcVar7;
  char *pcVar8;
  uint in_t0;
  uint in_SCOMPARE1;
  undefined1 uVar9;
  uint uVar10;
  undefined1 in_PRID;
  uint auStack_24 [9];
  
  uVar10 = 0;
  uVar3 = rsil(3);
  uVar5 = rsil(3);
  uVar2 = rsr(in_PRID);
  uVar4 = uVar2 ^ 0x6666;
  puVar1 = (uint *)&DAT_3ffbe0f8;
  pcVar8 = (char *)0x7be0f8;
  do {
    uVar6 = 0xb33fffff;
    if ((char *)0x3fffff < pcVar8) goto LAB_4011e3fc;
    memw();
    uVar10 = uVar10 & 0xffffcfff;
    auStack_24[0] = uVar2;
    FUN_4011e394(puVar1,0xb33fffff,auStack_24);
    while (uVar4 != auStack_24[0]) {
      if ((uVar2 == auStack_24[0]) || (auStack_24[0] == 0xb33fffff)) {
        uVar2 = puVar1[1];
        if ((uVar2 == 0) == (auStack_24[0] != 0xb33fffff)) {
          uVar6 = 0x7b;
          pcVar8 = "nlock.h";
          pcVar7 = "release";
        }
        else if (uVar2 < 0xff) {
          puVar1[1] = uVar2 + 1;
          uVar9 = (undefined1)uVar10;
          wsr(uVar9,uVar5);
          rsync();
          memw();
          uVar2 = *param_1;
          if (uVar2 == param_2) {
            memw();
            *param_1 = *param_3;
          }
          param_2 = rsil(3);
          uVar5 = rsr(in_PRID);
          param_1 = (uint *)*puVar1;
          if ((uint *)uVar5 == param_1) {
            param_1 = (uint *)(puVar1[1] - 1);
            puVar1[1] = (uint)param_1;
            if (param_1 == (uint *)0x0) {
              *puVar1 = 0xb33fffff;
LAB_4011e478:
              wsr(uVar9,param_2);
              rsync();
              memw();
              wsr(uVar9,uVar3);
              *param_3 = uVar2;
              memw();
              return;
            }
            puVar1 = (uint *)0xff;
            if (param_1 < 0x100) goto LAB_4011e478;
            pcVar8 = "->owner";
            uVar6 = 0xa4;
            pcVar7 = "< 0x100";
          }
          else {
            uVar6 = 0x9e;
            pcVar8 = " < 0xFF";
            pcVar7 = "< 0x100";
            memw();
          }
        }
        else {
          pcVar8 = "t == 0)";
          uVar6 = 0x7c;
          pcVar7 = "release";
        }
      }
      else {
        pcVar8 = "$";
        uVar6 = 0x7a;
        pcVar7 = "release";
      }
      uVar10 = uVar10 & 0xffffcfff;
      uVar4 = in_t0;
      (*(code *)&SUB_40094c54)("ude/soc/spinlock.h",uVar6,pcVar7);
      uVar5 = uVar4;
      uVar6 = extraout_a3;
      in_t0 = uVar4;
LAB_4011e3fc:
      wsr((char)in_SCOMPARE1,uVar6);
      auStack_24[0] = *puVar1;
      if (auStack_24[0] == in_SCOMPARE1) {
        *puVar1 = uVar2;
      }
      memw();
    }
  } while( true );
}

